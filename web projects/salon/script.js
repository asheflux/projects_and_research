// Description array women
var cardTextWomen = ["wash, cut & styling", "wash & style", "Perm", "Color", "Hair Smoothing", "Treatment", "Brow Thinning", "Brow Shaping" ,"Highlights"];
var cardPriceWomen = ["€ 55 – 95", "€ 30 - 60", "€ 70 – 225", "€ 60 – 115", "€ 60 – 152", "€ 20 – 65", "€ 10", "€ 10 – 15" ,"€ 75 – 205"];

// Decription array men
var cardTextMen = ['Wash, Cut & Styling', 'Color', 'Highlights', 'Perm'];
var cardPriceMen = ['€ 40 – 65', '€ 50 – 95', '€ 50 – 125', '€ 60 – 125'];

// Animation

// function women
function scrollButtonWomen() {
    var femUp = 1;
    var i = 0; 
    i < cardTextWomen.length;
    i < cardPriceWomen.length;
    
    // NEXT
    $(".carousel-control-next").click( function(){
        femUp++;
        i++;
        if (femUp > 9) {
            femUp = 1;
            i = 0;
        }
        $("#mobile-image").attr("src", "./img/fem-hair-" + femUp + ".png");
        $("#fem-mobile-description").text(cardTextWomen[i]);
        console.log(cardTextWomen[i]);

        $("#fem-mobile-price").text(cardPriceWomen[i]);
        console.log(cardPriceWomen[i]);
        
    });

    // PREV
    $(".carousel-control-prev").click( function(){
        femUp--;
        i--;
        if (femUp < 1) {
            femUp = 9;
            i = 8;
        }
        $("#mobile-image").attr("src", "./img/fem-hair-" + femUp + ".png");
        $("#fem-mobile-description").text(cardTextWomen[i]);
        console.log(cardTextWomen[i]);

        $("#fem-mobile-price").text(cardPriceWomen[i]);
        console.log(cardPriceWomen[i]);
    });
}

// function serviceSection() {
//     $('#men-mobile-bg').click(function(){
//         $('#tab-click-women').removeClass('active');
//         $('#tab-click-men').addClass('active');
//     });
//     $('#fem-mobile-bg').click(function(){
//         $('#tab-click-men').removeClass('active');
//         $('#tab-click-women').addClass('active');
//     });
// };



// function men

function scrollButtonMen() {
    var menUp = 1;
    var j = 0; 
    j < cardTextMen.length;
    j < cardPriceMen.length;
    
    // NEXT
    $(".carousel-control-next-men").click( function(){
        menUp++;
        j++;
        if (menUp > 4) {
            menUp = 1;
            j = 0;
        }
        $("#mobile-image-men").attr("src", "./img/m-hair-" + menUp + ".png");
        $("#men-mobile-description").text(cardTextMen[j]);
        console.log(cardTextMen[j]);

        $("#men-mobile-price").text(cardPriceMen[j]);
        console.log(cardPriceMen[j]);
        
    });

    // PREV
    $(".carousel-control-prev-men").click( function(){
        menUp--;
        j--;
        if (menUp < 1) {
            menUp = 4;
            j = 3;
        }
        $("#mobile-image-men").attr("src", "./img/m-hair-" + menUp + ".png");
        $("#men-mobile-description").text(cardTextMen[j]);
        console.log(cardTextMen[j]);

        $("#men-mobile-price").text(cardPriceMen[j]);
        console.log(cardPriceMen[j]);
    });
}

function serviceSection() {
    $('#men-mobile-bg').click(function(){
        $('#mobile-service-women').addClass('d-none');
        $('#mobile-service-men').removeClass('d-none');
        $('#tab-click-men').addClass('active');
        $('#tab-click-women').removeClass('active');
        $("#mobile-image").attr("src", "./img/m-hair-1.png");
        $("#fem-mobile-description").text(cardTextMen[0]);
        $("#fem-mobile-description").text(cardPriceMen[0]);
    });
    $('#fem-mobile-bg').click(function(){
        $('#mobile-service-men').addClass('d-none');
        $('#mobile-service-women').removeClass('d-none');
        $('#tab-click-women').addClass('active');
        $('#tab-click-men').removeClass('active');
        $("#mobile-image").attr("src", "./img/fem-hair-1.png");
        $("#fem-mobile-description").text(cardTextWomen[0]);
        $("#fem-mobile-price").text(cardPriceWomen[0]);
    });
};

// functionality
scrollButtonWomen();
scrollButtonMen();
serviceSection();


