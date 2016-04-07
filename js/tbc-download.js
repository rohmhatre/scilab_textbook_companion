$(document).ready(function(){
    //webroot = "http://"+location.hostname+"/";
    webroot = Drupal.settings.basePath;
    $('.tbc-category').live('change', function(){
        tbc_category = $('.tbc-category').val();
        $('.tbc-book-overall').css({'display' : 'none'});
        if(tbc_category != 0) {
            $.ajax({
                type : 'POST',
                url : webroot + "textbook_run_ajax",
                data : {
                    'category' : tbc_category
                },
                beforeSend: function() {
                },
                success : function(data) {
                    output = JSON.parse(data);
                    console.log(output['books']);
                    html_data = '';
                    $.each( output['books'], function( key, value ) {
                        html_data += "<option value='"+ key +"'>" + value + "</option>";
                    });
                    $('.tbc-book').html(html_data);
                    $('.tbc-book-main').css({'display' : 'block'});
                }
            });
        }
    });

    $('.tbc-book').live('change', function(){
        tbc_category = $('.tbc-category').val();
        tbc_book = $('.tbc-book').val();
        $('.tbc-after-book').css({'display' : 'none'});
        if(tbc_category != 0 && tbc_book != 0) {
            $.ajax({
                type : 'POST',
                url : webroot + "textbook_run_ajax",
                data : {
                    'category' : tbc_category,
                    'book' : tbc_book
                },
                beforeSend: function() {
                },
                success : function(data){
                    output = JSON.parse(data);
                    $('.tbc-book-details').html(output['details']);
                    $('.tbc-book-download').html(output['download']);
                    $('.tbc-book-download-pdf').html(output['downloadpdf']);
                    html_data = '';
                    $.each( output['chapters'], function( key, value ) {
                        html_data += "<option value='"+ key +"'>" + value + "</option>";
                    });
                    $('.tbc-chapter').html(html_data);
                    $('.tbc-book-block').css({'display' : 'block'});
                }
            });
        }
    });

    $('.tbc-chapter').live('change', function(){
        tbc_category = $('.tbc-category').val();
        tbc_book = $('.tbc-book').val();
        tbc_chapter = $('.tbc-chapter').val();
        $('.tbc-after-chapter').css({'display' : 'none'});
        if(tbc_category != 0 && tbc_book != 0 && tbc_chapter != 0) {
            $.ajax({
                type : 'POST',
                url : webroot + "textbook_run_ajax",
                data : {
                    'category' : tbc_category,
                    'book' : tbc_book,
                    'chapter': tbc_chapter
                },
                beforeSend: function() {
                },
                success : function(data){
                    output = JSON.parse(data);
                    $('.tbc-chapter-download').html(output['download']);
                    html_data = '';
                    $.each( output['examples'], function( key, value ) {
                        html_data += "<option value='"+ key +"'>" + value + "</option>";
                    });
                    $('.tbc-example').html(html_data);
                    $('.tbc-chapter-block').css({'display' : 'block'});
                }
            });
        }
    });

    $('.tbc-example').live('change', function(){
        tbc_category = $('.tbc-category').val();
        tbc_book = $('.tbc-book').val();
        tbc_chapter = $('.tbc-chapter').val();
        tbc_example = $('.tbc-example').val();
        $('.tbc-after-example').css({'display' : 'none'});
        if(tbc_category != 0 && tbc_book != 0 && tbc_chapter != 0 && tbc_example != 0) {
            $.ajax({
                type : 'POST',
                url : webroot + "textbook_run_ajax",
                data : {
                    'category' : tbc_category,
                    'book' : tbc_book,
                    'chapter': tbc_chapter,
                    'example': tbc_example
                },
                beforeSend: function() {
                },
                success : function(data){
                    output = JSON.parse(data);
                    $('.tbc-example-download').html(output['download']);
                    $('.tbc-example-files').html(output['files']);
                    $('.tbc-after-example').css({'display' : 'block'});
                }
            });
        }
    });
});
