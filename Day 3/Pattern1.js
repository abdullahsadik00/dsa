// Pattern 1
//         *******
//         *******
//         *******

function pattern(row, col) {
  let result = "";
  for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
      result += "*";
    }
    result += "\n";
  }
  console.log(result);
}

// pattern(4, 4);

/*
        Pattern 2
            *
            **
            ***
            ****
         */

function pattern2(row, col) {
  let result = "";
  for (let i = 0; i < row; i++) {
    for (let j = 0; j <= i; j++) {
      result += "*";
    }
    result += "\n";
  }
  console.log(result);
}

// pattern2(4, 4);
/*
        Pattern 3
            ****
            ***
            **
            *
         */
function pattern3(row, col) {
  let result = "";
  for (let i = 0; i < row; i++) {
    for (let j = col; j >= i; j--) {
      result += "*";
    }
    result += "\n";
  }
  console.log(result);
}

// pattern3(4, 4);

/*
        Pattern 4
1
2 2
3 3 3 
4 4 4 4 
         */

function pattern4(row, col) {
  let result = "";
  for (let i = 1; i <= row; i++) {
    for (let j = 1; j <= i; j++) {
      result += i;
    }
    result += "\n";
  }
  console.log(result);
}

// pattern4(4, 4);

// 1
// 1 2
// 1 2 3
// 1 2 3 4
function pattern5(row, col) {
  let result = "";
  for (let i = 1; i <= row; i++) {
    for (let j = 1; j <= i; j++) {
      result += j;
    }
    result += "\n";
  }
  console.log(result);
}

// pattern5(4, 4);

/*
        Pattern 5
          *
          * *
          * * *
          * *
          *
         */

function pattern6(row, col) {
  let result = "";
  for (let i = 0; i < 2 * row; i++) {
    let totalColInRows = i > row ? 2 * row - i : i;
    for (let j = 0; j < totalColInRows; j++) {
      result += "*";
    }
    result += "\n";
  }
  console.log(result);
}

// pattern6(4, 4);

/*
        Pattern 5 A
        1
        1 2
        1 2 3
        1 2
        1
         */

function pattern7(row, col) {
  let result = "";
  for (let i = 1; i < 2 * row; i++) {
    let totalColInRows = i > row ? 2 * row - i : i;
    for (let j = 1; j < totalColInRows; j++) {
      result += j;
    }
    result += "\n";
  }
  console.log(result);
}

//   pattern7(4,7)

/*
        Pattern 6
    * * * * * 
   * * * * * 
  * * * * * 
 * * * * * 
* * * * * 
         */
function pattern8(row, col) {
  let result = "";
  for (let i = 1; i <= row; i++) {
    for (let space = 1; space <= row - i; space++) {
      result += " ";
    }
    for (let j = 1; j <= col; j++) {
      result += "* ";
    }
    result += "\n";
  }
  console.log(result);
}
pattern8(5, 5);
