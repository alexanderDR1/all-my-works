const input = document.querySelector(".form__field");
const container = document.querySelector(".container");
const btn = document.querySelector("#btn");

btn.addEventListener("click", async()=>{
    const city = input.value;
    const key = "57d6f18e1e4546b21681d178da3328ae";
    const url = `https://api.openweathermap.org/data/2.5/weather?units=metric&q=${city}&appid=${key}`;

    try {

        const response = await fetch(url);
        const data = await response.json();

        const temp = data.main.temp;

        if (temp < 0) {
            container.innerHTML = `${temp} celcius 🎅`;
        }

        else if (temp > 0 && temp < 20) {
            container.innerHTML = `${temp} celcius 🧣`;
        }

        else if (temp > 20) {
            container.innerHTML = `${temp} celcius 😎`;
        }

/*         switch (data.main.temp) {
            case data.main.temp> 30: {
                emojy = "😎";
                container.innerHTML = `${data.main.temp} ${emojy}`
                break;
            }

            case data.main.temp < 20 && data.main.temp > 0 : {
                emojy = "🧣";
                container.innerHTML = `${data.main.temp} ${emojy}`
                break;
            }

            
            case data.main.temp < 0: {
                emojy = "🎅";
                container.innerHTML = `${data.main.temp} ${emojy}`
                break;
            }

        
            default:
                break;
        } */

        
    } catch (error) {
        console.log(error);
    }


})

