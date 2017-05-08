<?php
/* function to display books in progress */
function tbc_books_in_progress_all()
{
	$output = "";
	$query = db_select('list_of_category');
	$query->fields('list_of_category');
	$query->orderBy('id', 'ASC');
	$category_list = $query->execute();
	$query = "
  SELECT po.creation_date, pe.book as book, pe.author as author, pe.publisher as publisher,pe.edition as edition, pe.isbn as isbn, pe.year as year, pe.id as pe_id, loc.category_name as category, loc.category_id as cat_id
FROM textbook_companion_preference pe 
LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id
LEFT JOIN list_of_category loc on pe.category = loc.category_id
WHERE po.proposal_status IN (1,4) AND pe.approval_status = 1
ORDER BY po.creation_date DESC
  ";
	$result = db_query($query);
	$proposal_rows = array();
	$i = 1;
	$category_data = _tbc_list_of_category($preference_data->category);
	$output = "<hr>";
	while ($row = $result->fetchObject())
	{
		$proposal_date = date("d-m-Y", $row->creation_date); // remove comment to display year
		if ($row->category != NULL)
		{
			$category = $row->category;
		} //$row->category != NULL
		else
		{
			$category = "Not assigned";
		}
		$preference_rows[] = array(
			$i,
			$proposal_date,
			$row->book . "<br><br>[ Author: " . $row->author . ", Publisher: " . $row->publisher . ", Year: " . $row->year . ", Edition: " . $row->edition . ", ISBN: " . $row->isbn . " ]",
			$category
		);
		$i++;
	} //$row = $result->fetchObject()
	$preference_header = array(
		'No',
		'Proposal Date',
		'Book',
		'Category'
	);
	$output .= theme('table', array(
		'header' => $preference_header,
		'rows' => $preference_rows
	));
	return $output;
}
function _textbook_companion_list_of_new_category($category_id = NULL)
{
	$category .= "";
	if ($category_id != NULL)
	{
		$query = db_select('list_of_category');
		$query->fields('list_of_category');
		$query->condition('id', $category_id);
		$category_list = $query->execute();
		$category .= "<ul>";
	} //$category_id != NULL
	else
	{
		$category_list = db_query('SELECT * FROM list_of_category WHERE category_id != 0');
	}
	$i = 1;
	while ($category_list_data = $category_list->fetchObject())
	{
		$category .= "<li><a href=#$i>$category_list_data->maincategory</a></li>";
		$i++;
	} //$category_list_data = $category_list->fetchObject()
	$category .= "</ul>";
	return $category;
}
function _textbook_companion_list_of_new_category_display($category_id = NULL)
{
	$category .= "";
	if ($category_id != NULL)
	{
		$query = db_select('list_of_category');
		$query->fields('list_of_category');
		$query->condition('id', $category_id);
		$category_list = $query->execute();
		$category .= "<ul>";
	} //$category_id != NULL
	else
	{
		$category_list = db_query('SELECT * FROM list_of_category WHERE category_id != 0');
	}
	while ($category_list_data = $category_list->fetchObject())
	{
		$category .= "<li><h4>$category_list_data->maincategory</h4></li>";
		$query_sub_cat = db_select('list_of_subcategory');
		$query_sub_cat->fields('list_of_subcategory');
		$query_sub_cat->condition('maincategory_id', $category_id);
		$subcategory_list = $query_sub_cat->execute();
		$category .= "<ul>";
		while ($sub_category_list_data = $subcategory_list->fetchObject())
		{
			$preference_q = db_query("
      SELECT DISTINCT (tcbm.sub_category), los.subcategory, loc.category_id,loc.maincategory,
      pe.book as book, pe.author as author, pe.publisher as publisher, pe.year as year, pe.id as pe_id,
      po.approval_date as approval_date
      FROM textbook_companion_preference pe
      LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id
      LEFT JOIN textbook_companion_book_main_subcategories tcbm ON pe.id = tcbm.pref_id
      LEFT JOIN list_of_category loc ON tcbm.main_category = loc.category_id
      LEFT JOIN list_of_subcategory los ON tcbm.sub_category = los.subcategory_id
      WHERE po.proposal_status = 3 AND pe.approval_status = 1 AND pe.category>0
      AND pe.id = tcbm.pref_id AND tcbm.sub_category= :subcategory", array(
				":subcategory" => $sub_category_list_data->subcategory_id
			));
			$category .= "<li><h4>$sub_category_list_data->subcategory</h4></li>";
			while ($preference_data = $preference_q->fetchObject())
			{
				$category .= "<ul>";
				if ($sub_category_list_data->subcategory == $preference_data->subcategory && $sub_category_list_data->maincategory_id == $preference_data->category_id)
				{
					$category .= "<li>";
					$category .= l($preference_data->book . " by " . $preference_data->author . ", " . $preference_data->publisher . ", " . $preference_data->year, 'textbook_run/' . $preference_data->pe_id);
					$category .= "</li>";
				} //$sub_category_list_data->subcategory == $preference_data->subcategory && $sub_category_list_data->maincategory_id == $preference_data->category_id
				$category .= "</ul>";
			} //$preference_data = $preference_q->fetchObject()
		} //$sub_category_list_data = $subcategory_list->fetchObject()
		$category .= "</ul>";
	} //$category_list_data = $category_list->fetchObject()
	$category .= "</ul>";
	return $category;
}
function tbc_completed_books_all()
{
	$category_id = NULL;
	$output = "";
	$output = "<h4>Category</h4>";
	$output .= "<hr style='background-color: #abb2b8;' /><div style='width:50%; float:left;'>";
	$output .= _textbook_companion_list_of_new_category($category_id);
	$output .= "</div>";
	$result_count = db_query("SELECT pe.book FROM textbook_companion_preference pe LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id WHERE po.proposal_status =3 AND pe.approval_status =1 AND pe.category>0");
	$row_count = $result_count->rowCount();
	$output .= "<p style='clear: both;'>Total number of completed books : &nbsp;" . $row_count . " </p>";
	$output .= "<hr style='background-color: #abb2b8;' />";
	$result_category = db_query("SELECT * FROM list_of_category WHERE category_id !=0");
	$row_category_count = $result_category->rowCount();
	for ($i = 1; $i <= $row_category_count; $i++)
	{
		$output .= "<div id=$i>" . _textbook_companion_list_of_new_category_display($i) . "</div>";
	} //$i = 1; $i <= $row_category_count; $i++
	return $output;
}
