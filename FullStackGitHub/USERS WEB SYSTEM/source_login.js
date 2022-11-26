const loadFromLS = (key) =>{
    return JSON.parse(localStorage.getItem(key));
};

const saveToLS = (key, value) => {
    localStorage.setItem(key, JSON.stringify(value));
};

const users = loadFromLS("users") ? loadFromLS("users") : [];

const user_name = document.querySelector("#user_name");
const user_pass = document.querySelector("#user_pass");
const login_btn = document.querySelector("#login_btn");
const msg = document.querySelector("#message");

login_btn.addEventListener('click', ()=>{

    const exists_user = users.some(user => user.user_name === user_name.value);


    if (exists_user){

        const correct_user = users.findIndex(user => user.user_name === user_name.value);

        if (users[correct_user].user_pass === user_pass.value) {
            users[correct_user].user_online = true;
            msg.innerHTML= "login seccess";
            saveToLS("users", users);
            setTimeout(()=>{
                location.href = "./dashboard.html";
            },3000);
        }

        else {
            msg.innerHTML= "wrong username or password, try again";
        }
    }

    else {
        msg.innerHTML= "wrong username or password, try again";
    }
})