// Global variables
let scale = 1;

// SevenSegment variables
let number = 0;
let sevenSegment = new SevenSegment(500, 500);

function runSevenSegment() {
    sevenSegment.render(scale, number);
}

function setup() {
    createCanvas(window.innerWidth, window.innerHeight);
    rectMode(CENTER);
}

function draw() {
    background(0);
    runSevenSegment();
}