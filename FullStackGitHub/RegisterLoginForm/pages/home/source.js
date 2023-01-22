// import ls and ss functions
import {getDataFromLS,getDataFromSS,saveDataInLS,saveDataInSS} from '../../models/localStorage_actions.js'


//elements
const dashboard = document.querySelector("#dashboard");
const logout_btn = document.querySelector("#logout_btn");


// init user
let user = getDataFromLS("session_login")? getDataFromLS("session_login") : null;

if (user) {
    dashboard.textContent = `welcome ${user.name}`;
}
else {
    location.href = "../login/login.html"
}

logout_btn.addEventListener("click",(event)=>{
    event.preventDefault();
    localStorage.removeItem("session_login");
    setTimeout(()=>{
        location.reload();
    },1000)
})