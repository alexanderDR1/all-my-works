// משתנה שיכיל את הכסף בקופה
let credit = 0;

// משתנים שיכילו את מ חירי הפחיות
const cola_price = 9;
const fanta_price = 7;
const zero_price = 8;
const sprite_price = 5;

// מלאים של הפחיות
let cola_qty = 10;
let fanta_qty = 10;
let zero_qty = 10;
let sprite_qty = 10;


// אלמנטים שנעבוד איתם
const screen = document.querySelector("#screen");
const get_box = document.querySelector("#get_drink_final");
const odef = document.querySelector("#odef");

// מדפיסה כמה כסף יש בקופה
function printToScreen() {
    if (credit <= 9) {
        screen.innerHTML = `0${credit}.00`;
    }
    
    else {
        screen.innerHTML = `${credit}.00`;
    }
}

//פונקציה שמוסיפה כסף 
function addSh(coin) {
    odef.innerHTML = "";
    credit += coin;
    printToScreen()
}


// פונקציה שמחזירה עודף ומאפסת את הקופה
function reset() {
    odef.innerHTML = `היי העודף שלך הוא : ${credit} ש"ח`;
    screen.innerHTML = "00.00";
    credit = 0;
}


function choice_drink (drink) {


    switch(drink){
        case "cola" : {
            if (cola_qty >= 1) {
                if (credit >= cola_price) {
                    credit -= cola_price;
                    cola_qty--;
                    get_box.src = "/assets/img/drinks/cola_d.png";
                    printToScreen();
                    
                }
                else {
                    screen.innerHTML = `${cola_price} ש"ח`
                }
            }
            else {
                screen.innerHTML = "------";
                setTimeout(printToScreen, 4000);
            }
            break;
        }
        case "fanta" : {
            if (fanta_qty >= 1) {
                if (credit >= fanta_price) {
                    credit -= fanta_price;
                    fanta_qty--;
                    get_box.src = "/assets/img/drinks/fanta_d.png";
                    printToScreen();
                }
                else {
                    screen.innerHTML = `${fanta_price} ש"ח`
                }
            }
            else {
                screen.innerHTML = "------";
                setTimeout(printToScreen, 4000);
            }
            break;
        }
        case "zero" : {
            if (zero_qty >= 1) {
                if (credit >= zero_price) {
                    credit -= zero_price;
                    zero_qty--;
                    get_box.src = "/assets/img/drinks/zero_d.png";
                    printToScreen();
                }
                else {
                    screen.innerHTML = `${zero_price} ש"ח`
                }
            }
            else {
                screen.innerHTML = "------";
                setTimeout(printToScreen, 4000);
            }
            break;
        }
        case "sprite" : {
            if (sprite_qty >= 1) {
                if (credit >= sprite_price) {
                    credit -= sprite_price;
                    sprite_qty--;
                    get_box.src = "/assets/img/drinks/sprite_d.png";
                    printToScreen();
                }
                else {
                    screen.innerHTML = `${sprite_price} ש"ח`
                }
            }
            else {
                screen.innerHTML = "------";
                setTimeout(printToScreen, 4000);
            }
        }
    }
}


function getPahit() {
    reset();
    get_box.src =""
}