// elements
const container = document.querySelector(".container");

// api url's
const album_url = "https://jsonplaceholder.typicode.com/albums";
const photos_url = "https://jsonplaceholder.typicode.com/photos";
const user_url = "https://jsonplaceholder.typicode.com/users"

// static photo url
const static_img = "https://icon-library.com/images/img-icon/img-icon-14.jpg";

const buildPhotoCard =async (obj_photo, userId) =>{

    const card = document.createElement("div");
    card.classList.add("card");
    
    const img = document.createElement("img");
    img.src = obj_photo.url;
    
    const p = document.createElement("p");
    p.textContent = obj_photo.title;
    
    const b = document.createElement("b");
    
    
    try {
        const response = await fetch(`${user_url}/${userId}`);
        const user_data = await response.json();
        b.textContent = user_data.name;

    } catch (error) {
        console.log(error);
    }
    
    
    const btn = document.createElement("button");
    btn.textContent = "back";
    btn.addEventListener("click", () => {
        
        fetchAlbums();

    });
    
    
    
    card.append(img, p, b, btn);
    
    container.append(card);


}

// build album obj
const buildAlbumCard = (obj_album) => {

    const card = document.createElement("div");
    card.classList.add("card");
    card.setAttribute("id", obj_album.id);
    const img = document.createElement("img");
    img.src = static_img;

    const album_details = document.createElement("div");
    album_details.classList.add("album_details");

    const album_title = document.createElement("h2");
    album_title.textContent = obj_album.title;

    const album_number = document.createElement("b");
    album_number.textContent = `album number : ${[obj_album.id]}`;

    const btn = document.createElement("button");
    btn.textContent = "see photos";



    btn.addEventListener("click", async()=>{
        try {
            const response = await fetch(`${photos_url}?albumId=${obj_album.id}`);
            const photos = await response.json();
            
            container.innerHTML = "";
            for (let photo of photos) {
                buildPhotoCard(photo,obj_album.userId);
            }

        } catch (error) {
            console.log(error);
        }
    })


    album_details.append(album_title, album_number);
    card.append(img, album_details, btn);
    container.append(card);
}


const fetchAlbums = async () => {
    try {

        const response = await fetch(album_url);
        const albums = await response.json();

        container.innerHTML = "";
        albums.forEach(buildAlbumCard);
    } catch (error) {
        console.log(error);
    }

}




fetchAlbums();
