$.getJSON("https://api.myjson.com/bins/loqcy", { get_param: 'value' }, function(data) {
    $.each(data, function(index, element) {
        if(element.s1 >= 19 && element.s2 >= 19){
            $('<img>').attr( "src", "img/vazio.jpg").appendTo( ".main").addClass('shelf');
            $('.main').append($('<div>', {
                text: '['+ element.ID +'] Prateleira de '+ element.tipo + ' está vazia.'}
            ).addClass('emptyshelf'));
            $('.lateral').append($('<div>', {
                text: element.ID}).addClass('empty'));
        } else {
            $('<img>').attr( "src", "img/full.jpg" ).appendTo( ".main").addClass('shelf');
            $('.main').append($('<div>', {
                text: '['+ element.ID +'] Prateleira de '+ element.tipo + ' ainda possui produtos'}
            ).addClass('fullshelf'));
            $('.lateral').append($('<div>', {
                text: element.ID }).addClass('full'));
        }
    });
});