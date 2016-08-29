<?php
/* function to display books in progress */
function tbc_books_in_progress_all()
{
	$output = "";
	$query = db_select('list_of_category');
	$query->fields('list_of_category');
	$query->orderBy('id', 'ASC');
	$category_list = $query->execute();
	/*$output .= "<div style='width:35%; float:left;'><ul>";
	while ($category_list_data = $category_list->fetchObject())
	{
	if($category_list_data->category_id < 8){
	$output .= '<li><a href="'.$category_list_data->category_id.'#">'.$category_list_data->category_name.'</a></li>';
	}elseif($category_list_data->category_id == 8){
	$output .= "</ul></div><div style='width:35%; float:left;'><ul>";
	$output .= '<li><a href="'.$category_list_data->category_id.'#">'.$category_list_data->category_name.'</a></li>';
	}elseif($category_list_data->category_id > 7){
	$output .= '<li><a href="'.$category_list_data->category_id.'#">'.$category_list_data->category_name.'</a></li>';
	}elseif($category_list_data->category_id == 14){
	$output .= "</ul></div>";
	
	}
	}
	$output .= "</ul></div>";*/
	/*$query = "SELECT pe.book as book, pe.author as author, pe.publisher as publisher, pe.year as year, pe.id as pe_id
	FROM {textbook_companion_preference} pe LEFT JOIN {textbook_companion_proposal} po ON pe.proposal_id = po.id
	WHERE po.proposal_status IN (1,4) AND pe.approval_status = 1 AND pe.category = 9 ORDER BY pe.book ASC";*/
	$query = "
  SELECT po.creation_date, pe.book as book, pe.author as author, pe.publisher as publisher, pe.year as year, pe.id as pe_id, loc.category_name as category, loc.category_id as cat_id
FROM textbook_companion_preference pe 
LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id
LEFT JOIN list_of_category loc on pe.category = loc.category_id
WHERE po.proposal_status IN (1,4) AND pe.approval_status = 1  
ORDER BY po.creation_date ASC
  ";
	$result = db_query($query);
	$proposal_rows = array();
	$i = 1;
	$category_data = _tbc_list_of_category($preference_data->category);
	$output .= "<div style='width:100%'>";
	foreach ($category_data as $cat)
	{
		$output .= "<div style='width:100%'><br><strong><h3>" . $cat . "</h3></strong><hr>";
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
				$row->book,
				$row->author,
				$category
			);
			$i++;
		} //$row = $result->fetchObject()
		$preference_header = array(
			'No',
			'Proposal Date',
			'Book',
			'Author',
			'Category'
			//'Year' // remove comment to display year
		);
		$output .= theme('table', array(
			'header' => $preference_header,
			'rows' => $preference_rows
		));
	} //$category_data as $cat
	$output .= "</div>";
	return $output;
}
