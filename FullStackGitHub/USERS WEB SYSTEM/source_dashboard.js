const loadFromLS = (key) =>{
    return JSON.parse(localStorage.getItem(key));
};

const saveToLS = (key, value) => {
    localStorage.setItem(key, JSON.stringify(value));
};

const users = loadFromLS("users") ? loadFromLS("users") : [];

const user_name = document.querySelector("#user_name");
const user_mail = document.querySelector("#user_mail");
const delete_btn = document.querySelector("#delete_btn");
const logout_btn = document.querySelector("#logout_btn");

const correct_user = users.findIndex(user => user.user_online === true);


const user = users[correct_user];

user_name.innerHTML = `${user.user_name}`;
user_mail.innerHTML = `${user.user_mail}`;

delete_btn.addEventListener('click', ()=> {
    users.splice(correct_user,1);
    saveToLS("users", users);
    location.href = "./index.html";
})

logout_btn.addEventListener('click', ()=> {
    users[correct_user].user_online = false;
    saveToLS("users", users);
    location.href = "./index.html";
})