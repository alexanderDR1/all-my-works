const btn = document.querySelector("#btn");
const kelet = document.querySelector("#kelet");
const url = "https://data.gov.il/api/3/action/datastore_search?resource_id=c8b9f9c8-4612-4068-934f-d4acd2e3c06e&limit=186500";
const result = document.querySelector("#result");

let array;

btn.addEventListener("click", async()=>{
    let kelet_value = kelet.value;

    try {
        const response = await fetch(url);
        const data = await response.json();
        array = data.result.records;
        
        let answer = array.find(tav =>tav['MISPAR RECHEV'] == kelet_value);

        if (!answer) {
            result.innerHTML = "לא נמצא תו נכה לרכב זה"
        } else {
            result.innerHTML = `יש לרכב זה תו נכה והופק בתאריך : ${answer['TAARICH HAFAKAT TAG']}`;
        }


    } catch (error) {
        console.log(error);
    } finally {
        console.log("done");
    }

})