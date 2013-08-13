$( document ).ready(function() {

$('#edit-same-address').click(function() {
    var temp = $('#edit-chq-address').val();
    $('#edit-temp-chq-address').val(temp);
    var temp1 = $('#edit-perm-city').val();
    $('#edit-temp-city').val(temp1);
    var temp1 = $('#edit-perm-pincode').val();
    $('#edit-temp-pincode').val(temp1);
    var temp1 = $('#edit-perm-state').val();
    $('#edit-temp-state').val(temp1);

	$("#edit-cheque-sent").datepicker();


	$("#edit-cheque-cleared").datepicker();

});

$("#edit-perm-pincode").blur(function() 
    { 
        var string_length,string_val; 
        string_val = $("#edit-perm-pincode").val();
        string_length = $("#edit-perm-pincode").text().length; 
        //$("#username_warning").empty(); 
 
        if ((isNaN(string_val))&&(string_length < 6))
        alert("Not A Valid Zip Code!!");
        
           // $("#username_warning").append("Username is too short"); 
    }); 
$("#edit-temp-pincode").blur(function() 
    { 
        var string_length1,string_val1; 
        string_val = $("#edit-temp-pincode").val();
        string_length = $("#edit-temp-pincode").text().length; 
        //$("#username_warning").empty(); 
 
        if ((isNaN(string_val))&&(string_length1 < 6))
        alert("Not A Valid Zip Code!!");
        
           // $("#username_warning").append("Username is too short"); 
    }); 

$("#edit-mobileno1").blur(function() 
    { 
        var string_length3,string_val3; 
        string_val3 = $("#edit-mobileno1").val();
        string_length3 = $("#edit-mobileno1").text().length; 
        //$("#username_warning").empty(); 
 
        if (isNaN(string_val3))
	{
		alert("Mobile No should be a number!!");
           // $("#username_warning").append("Username is too short"); 
	}
        if((string_length3 > 0)&&(string_length3 < 11))
	{
        		alert("Not A Valid Mobile No!!");
        }
    }); 

$("#edit-mobileno2").blur(function() 
    { 
        var string_length4,string_val4; 
        string_val4 = $("#edit-mobileno2").val();
        string_length4 = $("#edit-mobileno2").text().length; 
        //$("#username_warning").empty(); 
 
        if (isNaN(string_val4))
	{
		alert("Mobile No should be a number!!");
	        // $("#username_warning").append("Username is too short"); 
	}
        if((string_length4 > 0)&&(string_length4 < 11))
	{
        		alert("Not A Valid Mobile No!!");
        }
    });
$('#edit-older-wrapper').hide();
$('#edit-version').change(function() {
    var selected = $(this).val();
    //$('#edit-older-wrapper').hide();
    if(selected == 'olderversion'){
         $('#edit-older-wrapper').show();
    }
    else
    {
	$('#edit-older-wrapper').hide();
    }
    
});
});


