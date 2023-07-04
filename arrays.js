const strings= ['a', 'b', 'c', 'd'];
const numbers = [1,2,3,4,5];
// Variable array is somewhere in memory and the computer knows it.
// When I do array[2], i'm telling the computer, hey go to the array and grab the 3rd item from where the array is stored.

//push
strings.push('e');

//pop
strings.pop();
strings.pop();

//unshift
strings.unshift('x')

//splice
strings.splice(2, 0, 'alien');

console.log(strings)

class Player {
    constructor(name,type){
        console.log(this)
        this.name = name
        this.type = type
    }
    introduce(){
        console.log(`Hi my name is ${this.name}, and I'm a ${this.type}`)
    }
}

class Mage extends Player{
    constructor(name,type){
        super(name,type)
        console.log(this)
    }
    play(){
        console.log(`I am a ${this.type}`)
    }
} 

class Team extends Mage{
    constructor(name,type,team){
        super(name,type)
        this.team = team
    }
    introduction(){
        console.log(`Hi my name is ${this.name},I'm a ${this.type} and I'm in ${this.team} team`)
    }
}
const mage1 = new Mage("Sadik","Healer")
const team1 = new Team("Sadik","Healer","Saviour")
team1.introduction()
