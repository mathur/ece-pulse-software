var count = 0;
var name = "#random";
$(document).ready(function() {

    $( "#fetch-more-photos" ).click(function() {
	var the_url = "https://placeholdit.imgix.net/~text?txtsize=33&txt=350%C3%97150&w=350&h=150"
	
	var txt1 = ('<article class="work-item"><a href="#" class="image fit thumb"><img id="random'+count+'" src="'+ the_url+ '" alt="" /></a><h3>Risus ornare lacinia</h3><p>Lorem ipsum dolor sit amet nisl sed nullam feugiat.</p></article>')
        $("#carousel-container").append(txt1);
        var lmao = name + count;
        var lol = true;
        lol = getPicture('borisss1982', function(url) {
    		$(lmao).attr("src", url)
    		count++;
		});


        return false;
    });



});

function getPicture(tags, cb) {
    var apiKey = "fa214b1215cd1a537018cfbdfa7fb9a6"; // replace this with your API key

    // get an array of random photos
    $.getJSON(
        "https://api.flickr.com/services/rest/?jsoncallback=?", {
            method: 'flickr.photos.search',
            tags: tags,
            api_key: apiKey,
            format: 'json',
            nojsoncallback: 1,
            per_page: 10 // you can increase this to get a bigger array
        },
        function(data) {

            // if everything went good
            if (data.stat == 'ok') {
                // get a random id from the array
                var photo = data.photos.photo[Math.floor(Math.random() * data.photos.photo.length)];

                // now call the flickr API and get the picture with a nice size
                $.getJSON(
                    "https://api.flickr.com/services/rest/?jsoncallback=?", {
                        method: 'flickr.photos.getSizes',
                        api_key: apiKey,
                        photo_id: photo.id,
                        format: 'json',
                        nojsoncallback: 1
                    },
                    function(response) {
                        if (response.stat == 'ok') {
                            var the_url = response.sizes.size[5].source;
                            cb(the_url);
                        } else {
                            console.log(" The request to get the picture was not good :\ ")
                        }
                    }
                );

            } else {
                console.log(" The request to get the array was not good :( ");
            }
        }
    );
	return false;
};

$(function(){
	$('#carousel-container article').hide().filter(':first').show();
	setInterval(slideshow, 3000);
});

function slideshow() {
	$('#carousel-container article:first').fadeOut('slow').next().fadeIn('slow').end().appendTo('#carousel-container');
}
