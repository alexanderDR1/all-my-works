const loadFromLS = (key) =>{
    return JSON.parse(localStorage.getItem(key));
};

const saveToLS = (key, value) => {
    localStorage.setItem(key, JSON.stringify(value));
};

const users = loadFromLS("users") ? loadFromLS("users") : [];


const user_name = document.querySelector("#user_name");
const user_pass = document.querySelector("#user_pass");
const user_mail = document.querySelector("#user_mail");
const register_btn = document.querySelector("#register_btn");
const msg = document.querySelector("#message");

register_btn.addEventListener('click' ,()=>{

    const exists_user = users.some(user => user.user_name === user_name.value);

    if (exists_user) {
        msg.innerHTML = 'this user name is already exists';
    }

    else {

        const user = {
            user_name : user_name.value,
            user_pass : user_pass.value,
            user_mail : user_mail.value,
            user_online : false
        };
    
        users.push(user);
        saveToLS("users", users);
        msg.innerHTML = "register seccess"
        setTimeout(()=>{
            location.href = "./index.html";
        },3000)

    }



});

