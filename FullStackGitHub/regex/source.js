
/* let str = "HELLO google hi microsoft i love GOOGLE and not microsoft";

str =  str.replace(/microsoft/, "meta");

console.log(str); */

const str = "vfvffvFF333";

const regex = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,15}$/;

const result = regex.test(str);

console.log(result);

// a+ = הכוונה לאות a אחת או יותר
// .+ = הכוונה היא לכל סימן אחד או יותר