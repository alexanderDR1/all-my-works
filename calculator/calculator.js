const para = document.querySelector("#result > p");
let txt  = "";

const printToResult = (key)=>{
  if(txt == 0){
    txt = "";
    txt += key;
    para.innerHTML = txt;
  }
  else{
    txt  += key;
    para.innerHTML = txt
  }
  
}

const showResult = ()=>{
  

  try{
    let final = eval(txt);
    txt = final;
    para.innerHTML  = final;

  }
  catch(error){
    para.innerHTML ="Error";
  }
  finally{
    console.log("ok");
  }

}

const clearTheResult = ()=>{
  txt  = "0";
  para.innerHTML = txt;
}
