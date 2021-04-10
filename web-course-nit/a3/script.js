class BarsView {
    /**
     * 
     * @param {Number} width 
     * @param {Number} height 
     * @param {Array} bars 
     */
    constructor(width, height, bars) {
        this.width = width
        this.height = height
        this.bars = bars

        this.init()
    }

    init() {
        // Width
        let all_gaps = 200
        let count = this.bars.length
        let free = this.width - all_gaps
        this.each_width = free / count
        this.bar_width = this.each_width * 2 / 3
        this.gap_between = this.each_width / 3

        // Height
        this.max_height = this.bars.reduce((a, b) => Math.max(a, b))
        this.min_height = this.bars.reduce((a, b) => Math.min(a, b))
    }

    render() {
        let i = 0
        let x = 100

        this.bars.forEach(bar => {
            let width = this.bar_width
            let height = map(bar, 0, this.max_height, 0, this.height / 2)
            let x = 100 + i * this.each_width + width / 2
            let y = 10 + height / 2

            rect(x, y, width, height)
            i += 1
        })
    }
}

let w = window.innerWidth
let h = window.innerHeight
let arr = [254, 123, 301, 992, 510, 111, 209, 173, 170, 200]
arr.sort()
let bars = new BarsView(w, h, arr)

function setup() {
    createCanvas(w, h)
    rectMode(CENTER)
    fill('black')
    stroke('white')
}

function draw() {
    background(0)
    bars.render()
}
