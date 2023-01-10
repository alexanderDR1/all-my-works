
const url = "https://api.coincap.io/v2/assets";
const t_body = document.querySelector("tbody");
const search_bar = document.querySelector("#search_bar");

const loadImage = async(query) =>{
    try {
        const response = await fetch(`https://pixabay.com/api/?key=14412042-9942eafd3a85fd8ed0cb0d3bd&q=${query}&image_type=photo&pretty=true`);
        const data = await response.json();
        const final = data.hits[0].previewURL;
        return final;
    } catch (error) {
        return `https://cdn.pixabay.com/photo/2013/03/02/02/21/space-89132_150.jpg`;
    }

}

const buildNewTableRow = async(obj) => {
    try {
        const new_tr = document.createElement("tr");

        const new_td_1 = document.createElement("td");
        const new_td_2 = document.createElement("td");
        const new_td_3 = document.createElement("td");
        const new_td_4 = document.createElement("td");
        const new_td_5 = document.createElement("td");
      
        const img = document.createElement("img");
        img.style = "max-width : 50px;";
      
        const url = await loadImage(obj.name) ? await loadImage(obj.name) : await loadImage(obj.symbol) 
        img.src = url;
      
        new_td_1.append(img);
        new_td_2.append(obj.rank);
        new_td_3.append(obj.symbol);
        new_td_4.append(obj.name);
        new_td_5.append(obj.priceUsd);
      
        new_tr.append(new_td_1, new_td_2, new_td_3, new_td_4, new_td_5);
        t_body.append(new_tr);
    } catch (error) {
        console.log(error);
    }
};

let data;

const getData = async (link) => {
  try {
    const response = await fetch(link);
    data = await response.json();

    for (let coin of data.data) {
      buildNewTableRow(coin);
    }
  } catch (error) {
    console.log(error);
  } finally {
    console.log("fetch request done");
  }
};

getData(url);

search_bar.addEventListener("input", (event) => {
  const value = event.target.value;

  const filtered_coins = data.data.filter(
    (coin) =>
      coin.name.toLowerCase().includes(value.toLowerCase()) ||
      coin.symbol.toLowerCase().includes(value.toLowerCase())
  );

  t_body.innerHTML = "";
  if (filtered_coins.length == 0) {
    t_body.innerHTML = "לא נמצאו תוצאות";
  } else {
    for (let school of filtered_coins) {
      buildNewTableRow(school);
    }
  }
});
