// תפיסת אלמנטים מהדף
const board = document.querySelector("#note_board");
const content = document.querySelector("#noteTxt");
const time = document.querySelector("#noteTime");
const date = document.querySelector("#noteDate");
const btn = document.querySelector("#addNote");
const search_value = document.querySelector("#search_value");


// פונקציה שמקבלת מילת מפתח ומחפשת ומחזירה מאחסון הדפדפן את הערך + ממירה אותו חזרה לאובייקט
const loadFromLocalStorage = (key) => {
    return JSON.parse(localStorage.getItem(key));
};

// שומרת באחסון הדפדפן ערכים לפי המילת מפתח שהיא מקבלת + ממירה את האובייקטים לסטרינג
const saveInLocalStorage = (key, value) => {
    localStorage.setItem(key, JSON.stringify(value));
};

// מנסים להחזיר מידע מאחסון הדפדפן במידה וקיים אחרת מאפסים למערך ריק
let notes = loadFromLocalStorage("notes") ? loadFromLocalStorage("notes") : [];

// מנסים להחזיר מידע של איידי לפתק מאחסון הדפדפן אחרת מאפסים למספר אפס
let note_id = loadFromLocalStorage("note_id") ? loadFromLocalStorage("note_id") : 0;




// פונקציה שמקבלת אובייקט ובונה ממנו פתק בדף
const addNoteToHtml = (note_obj) => {

    let new_textarea;
    let new_time;
    let new_date;


    // יצירת האלמנטים והשמת ערך לאלמנטים
    const note_div = document.createElement("div");
    note_div.classList.add("note");

    const para_content = document.createElement("p");
    para_content.innerHTML = note_obj.content;

    para_content.addEventListener("click", () => {

        new_textarea = document.createElement("textarea");
        new_textarea.style.maxWidth = "70%";
        new_textarea.append(para_content.innerHTML);
        note_div.replaceChild(new_textarea, para_content);

        const update_btn = document.createElement("button");
        update_btn.append("UPDATE");
        note_div.replaceChild(update_btn, delete_btn);

        update_btn.addEventListener("click", () => {
            // מוצא את האיבר במערך לפי האיידי שלו
            notes.find(note => note.note_id === note_obj.note_id).content = new_textarea.value;
            // שמירה של המערך המעודכן באחסון הדפדפן
            saveInLocalStorage("notes", notes);
            // מאפס את הלוח בדף
            board.innerHTML = "";
            // לולאה שרצה בסריפט הגלובלי שבונה מכל איבר במערך של הפתקים פתק בדף
            for (let eivar of notes) {
                addNoteToHtml(eivar);
            }
        })

    });



    const para_time = document.createElement("p");
    para_time.innerHTML = note_obj.time;


    para_time.addEventListener("click", ()=> {

        new_time = document.createElement("input");
        new_time.setAttribute("type", "time");
        new_time.value = para_time.innerHTML;
        new_time.style.maxWidth = "50%";
        note_div.replaceChild(new_time, para_time);


        const update_btn = document.createElement("button");
        update_btn.append("UPDATE");
        note_div.replaceChild(update_btn, delete_btn);

        update_btn.addEventListener("click", () => {
            // מוצא את האיבר במערך לפי האיידי שלו
            notes.find(note => note.note_id === note_obj.note_id).time = new_time.value;
            // שמירה של המערך המעודכן באחסון הדפדפן
            saveInLocalStorage("notes", notes);
            // מאפס את הלוח בדף
            board.innerHTML = "";
            // לולאה שרצה בסריפט הגלובלי שבונה מכל איבר במערך של הפתקים פתק בדף
            for (let eivar of notes) {
                addNoteToHtml(eivar);
            }
        })

    })


    const para_date = document.createElement("p");
    para_date.innerHTML = note_obj.date;

    para_date.addEventListener("click", ()=>{

        new_date = document.createElement("input");
        new_date.setAttribute("type", "date");
        new_date.style = "max-width: 70%; margin-bottom: 20px";
        new_date.value = para_date.innerHTML;
        note_div.replaceChild(new_date, para_date);

        const update_btn = document.createElement("button");
        update_btn.append("UPDATE");
        note_div.replaceChild(update_btn, delete_btn);

        update_btn.addEventListener("click", () => {
            // מוצא את האיבר במערך לפי האיידי שלו
            notes.find(note => note.note_id === note_obj.note_id).date = new_date.value;
            // שמירה של המערך המעודכן באחסון הדפדפן
            saveInLocalStorage("notes", notes);
            // מאפס את הלוח בדף
            board.innerHTML = "";
            // לולאה שרצה בסריפט הגלובלי שבונה מכל איבר במערך של הפתקים פתק בדף
            for (let eivar of notes) {
                addNoteToHtml(eivar);
            }
        })

    })
    const delete_btn = document.createElement("button");
    delete_btn.innerHTML = "DELETE";

    // האזנה לקליק על כפתור מחיקה
    delete_btn.addEventListener("click", () => {

        // מחיקת הפתק על ידי סינון של המערך שיכיל את כל מי שאין לו את האיידי של הפתק
        notes = notes.filter(note => note.note_id !== note_obj.note_id);

        // שמירה של המערך המעודכן באחסון הדפדפן
        saveInLocalStorage("notes", notes);

        // הסרה של הפתק מהדף
        note_div.remove();

    });


    // הטמעת כל האלמנטים שיוצרים את הפתק בדיב של הפתק
    note_div.append(para_content, para_time, para_date, delete_btn);

    // הטמעת הפתק בלוח בדף
    board.append(note_div);

}


// מאזין לאירוע קליק של הוספת פתק
btn.addEventListener("click", () => {

    note_id++;

    // יוצר אובייקט של פתק מסודר ולוקח את הערכים מהשדות קלט
/*     const note = {
        note_id: note_id,
        content: content.value,
        time: time.value,
        date: date.value,
    }; */

    const note = new Note(note_id, content.value, time.value, date.value);

    // מוסיפים למערך הפתקים את האובייקט החדש
    notes.push(note);

    // שומר באחסון הדפדפן את המערך של הפתקים המעודכן
    saveInLocalStorage("notes", notes);

    // שומר באחסון הדפדפן את האיידי האחרון המעודכן
    saveInLocalStorage("note_id", note_id);

    // קורא לפוקציה שיודעת לבנות פתק בדף ומעבירים לה את האובייקט שיצרנו
    addNoteToHtml(note);


    // מאפס את השדות קלט
    content.value = "";
    time.value = "";
    date.value = "";
});


// לולאה שרצה בסריפט הגלובלי שבונה מכל איבר במערך של הפתקים פתק בדף
for (let eivar of notes) {
    addNoteToHtml(eivar);
}

// האזנה לאירוע הקלדת ערך בשורת חיפוש
search_value.addEventListener("keyup", () => {

    // יצירת מערך חדש מסונן שמתאים למה שיש בערך של השורת חיפוש
    // לפי תוכן או זמן או תאריך
    const filtered_array = notes.filter(note =>
        note.content.includes(search_value.value) ||
        note.time.includes(search_value.value) ||
        note.date.includes(search_value.value)
    );

    // מאפס את הלוח בדף
    board.innerHTML = "";


    // במידה והמערך מכיל איברים זאת אומרת שיש התאמה לחיפוש
    if (filtered_array.length > 0) {

        // לולאה שרצה בסריפט הגלובלי שבונה מכל איבר במערך של הפתקים המסונן פתק בדף
        for (let note of filtered_array) {
            addNoteToHtml(note);
        }
    }

    // במידה והמערך ריק
    else {
        board.innerHTML = "לא נמצאו תוצאות"
    }

});


