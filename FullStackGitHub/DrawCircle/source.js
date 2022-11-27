
let c = document.getElementById("myCanvas");
let input = document.querySelector("#input");
let btn = document.querySelector("#btn");
let reload = document.querySelector("#reload");
let ctx = c.getContext("2d");
ctx.beginPath();



btn.addEventListener("click",()=>{
  
  ctx.arc(150, 75, input.value, 0, 2 * Math.PI);
  ctx.fillStyle = 'red';
  ctx.fill();
  ctx.stroke();
  
})

reload.addEventListener("click", ()=>{
  location.reload();
})