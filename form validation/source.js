const tofes = document.querySelector("#tofes");
const result = document.querySelector("#result");

const user_name = document.querySelector("#user_name");
const user_name_msg = document.querySelector("#user_name_msg");

const user_email = document.querySelector("#user_email");
const user_email_msg = document.querySelector("#user_email_msg");

const user_pass = document.querySelector("#user_pass");
const user_pass_msg = document.querySelector("#user_pass_msg");

const user_pass_confirm = document.querySelector("#user_pass_confirm");
const user_pass_confirm_msg = document.querySelector("#user_pass_confirm_msg");

let user_name_valid = false ;
let user_email_valid = false ;
let user_pass_valid = false ;
let user_pass_confirm_valid = false ;

// regular expressions

const user_name_regex = /^[A-Za-z0-9]{6,15}$/;
const user_email_regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
const user_pass_regex = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,15}$/;


user_name.addEventListener("input", ()=>{


    if(user_name_regex.test(user_name.value)) {
        user_name_msg.innerHTML = "✔";
        user_name_msg.style.color = "green";
        user_name_valid = true;
    }

    else {
        user_name_valid = false;
        user_name_msg.innerHTML = "שם משתמש חייב להיות בין 6 ל15 תווים";
        user_name_msg.style.color = "red";
    }

});


user_email.addEventListener("input", ()=>{
    
    if(user_email_regex.test(user_email.value)) {
        user_email_valid = true;
        user_email_msg.innerHTML = "✔";
        user_email_msg.style.color = "green";
    }

    else {
        user_email_valid = false;
        user_email_msg.innerHTML = "אנא הכנס מייל תקין";
        user_email_msg.style.color = "red";
    }

});

user_pass.addEventListener("input", ()=>{

    user_pass_confirm.value = "";
    user_pass_confirm_msg.innerHTML = "";
    user_pass_confirm_valid = false;
    
    if(user_pass_regex.test(user_pass.value)) {
        user_pass_valid = true;
        user_pass_msg.innerHTML = "✔";
        user_pass_msg.style.color = "green";
    }

    else {
        user_pass_valid = false;
        user_pass_msg.innerHTML = "אנא הכנס סיסמא תקינה";
        user_pass_msg.style.color = "red";
    }

});

user_pass_confirm.addEventListener("input", ()=>{
     
    if (user_pass.value == user_pass_confirm.value) {
        user_pass_confirm_valid = true;
        user_pass_confirm_msg.innerHTML = "✔";
        user_pass_confirm_msg.style.color = "green";
    }

    else {
        user_pass_confirm_valid = false;
        user_pass_confirm_msg.innerHTML = "סיסמאות לא זהות";
        user_pass_confirm_msg.style.color = "red";
    }
});

tofes.addEventListener("submit", (e)=>{

    e.preventDefault();

    if (user_name_valid && user_email_valid && user_pass_valid && user_pass_confirm_valid) {
        result.innerHTML = "הטופס תקין וישלח בהצלחה";
        result.style.color = "green";
        user_name.value = "";
        user_email.value = "";
        user_pass.value = "";
        user_pass_confirm.value = "";
        user_name_msg.innerHTML = "";
        user_email_msg.innerHTML = "";
        user_pass_msg.innerHTML = "";
        user_pass_confirm_msg.innerHTML = "";
    } 
    else {
        result.innerHTML = "נא השלם כמו שצריך את כל השדות"
        result.style.color = "red";
    }
})