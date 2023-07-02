//#1 -- For loop in Javascript.
const fish = ['dory', 'bruce', 'marlin', 'nemo'];
const nemo = ['nemo'];
const everyone = ['dory', 'bruce', 'marlin', 'nemo', 'gill', 'bloat', 'nigel', 'squirt', 'darla', 'hank'];
const large = new Array(100).fill("nemo")

function findNemo(array){
    for(let i = 0 ; i < array.length ; i++){
        if(array[i] === "nemo"){
            console.log("Found it")
        }
    }
}
// Complexity O(n)
// findNemo(nemo) 
// ============================================================

const findNemo2 = (fish)=>{
    let t0 = performance.now();
    for(let i = 0; i < fish.length; i++){
        if(fish[i] === "nemo"){
            console.log("Found It")
        }
    }
    let t1 = performance.now()
    console.log("Call to find nemo took " + (t1 - t0) + "milliseconds")
}
// Complexity O(n)
// findNemo2(everyone)
// ============================================================

// What is the Big O of the below function? (Hint, you may want to go line by line)
function funChallenge(input) {
    let a = 10;
    a = 50 + 3;
  
    for (let i = 0; i < input.length; i++) {
      anotherFunction();
      let stranger = true;
      a++;
    }
    return a;
  }
//   Answer is O(n)
// ============================================================

// What is the Big O of the below function? (Hint, you may want to go line by line)
function anotherFunChallenge(input) {
    let a = 5;
    let b = 10;
    let c = 50;
    for (let i = 0; i < input; i++) {
      let x = i + 1;
      let y = i + 2;
      let z = i + 3;
  
    }
    for (let j = 0; j < input; j++) {
      let p = j * 2;
      let q = j * 2;
    }
    let whoAmI = "I don't know";
  }
//   Answer is O(n)
// ============================================================

function printFirstItemThenFirstHalfThenSayHi100Times(items) {
    console.log(items[0]);
    let middleIndex = Math.floor(items.length / 2);
    let index = 0;

    while (index < middleIndex) {
        console.log(items[index]);
        index++;
    }
    for (let i = 0; i < 100; i++) {
        console.log('hi');
    }
}