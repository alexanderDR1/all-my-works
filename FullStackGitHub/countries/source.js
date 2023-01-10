const container = document.querySelector(".container");
const search_input = document.querySelector(".input");
const url = "https://restcountries.com/v3.1/all";

const buildCardToHtml = (obj) => {
  const main_div = document.createElement("div");
  main_div.setAttribute("class", "card");

  const card_img = document.createElement("div");
  card_img.setAttribute("class", "card-img");
  const img = document.createElement("img");
  img.setAttribute("src", obj.flags.png);
  card_img.append(img);
  img.addEventListener("click",async()=>{
    try {
/*       const response = await fetch(`https://restcountries.com/v3.1/name/${obj.name.common}`);
      const data = await response.json();
      console.log(data); */
      

      container.innerHTML = "";
      buildCardToHtml(obj);

    }
    catch(err){
      console.log(err);
    }

  })

  const card_info = document.createElement("div");
  card_info.setAttribute("class", "card-info");
  const p1 = document.createElement("p");
  p1.innerHTML = obj.name.common;
  p1.setAttribute("class", "text-title");
  const p2 = document.createElement("p");
  p2.innerHTML = obj.capital[0];
  p2.setAttribute("class", "text-body");
  card_info.append(p1, p2);

  const card_footer = document.createElement("div");
  card_footer.setAttribute("class", "card-footer");
  const span = document.createElement("span");
  span.innerHTML = Object.values(obj.currencies)[0].symbol;
  span.setAttribute("class", "text-title");
  card_footer.append(span);

  main_div.append(card_img, card_info, card_footer);
  container.append(main_div);
};

let data;

const fetchCountries = async (link) => {
  try {
    const response = await fetch(link);
    data = await response.json();
    for (let country of data) {
      buildCardToHtml(country);
    }
  } catch (error) {
    console.log("error : " + error);
  }
};

fetchCountries(url);

search_input.addEventListener("input", (event) => {
  const filtered_countries = data.filter(ctr => ctr.name.common.toLowerCase().includes(event.target.value.toLowerCase()));
  container.innerHTML = "";

  if (filtered_countries.length == 0) {
    container.innerHTML = "not found countries";
  }
  else {
    for (let fc of filtered_countries) {
      buildCardToHtml(fc);
    }
  }


});
