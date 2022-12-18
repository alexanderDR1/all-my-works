const colors = ["blue", "green", "yellow", "red","lightblue"];
let interval;

document.querySelectorAll(".container > header >.left-header > a").forEach(item => {
  item.addEventListener("mouseover", rainbow, false);
  item.addEventListener("mouseout", stop, false);
});

function rainbow() {
  this.style.color = colors[Math.floor(Math.random() * colors.length)];
  interval = setTimeout(() => rainbow.call(this), 250);
}

function stop() {
  clearInterval(interval);
  this.style.color = "black";
}