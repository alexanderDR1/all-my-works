// functions to work with LS

// get data from ls (with json process)
export const getDataFromLS = (key)=>{
    return JSON.parse(localStorage.getItem(key));
}

// save data in ls (with json process)
export const saveDataInLS = (key, value)=>{
    localStorage.setItem(key,JSON.stringify(value));
}

// get data from ss (with json process)
export const getDataFromSS = (key)=>{
    return JSON.parse(sessionStorage.getItem(key));
}

// save data in ss (with json process)
export const saveDataInSS = (key, value)=>{
    sessionStorage.setItem(key,JSON.stringify(value));
}