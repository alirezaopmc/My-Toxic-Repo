class Segment {
    constructor(x, y, w, h) {
        this.on = false;
        this.geo = new Rectangle(x, y, w, h)
    }

    render(scale = 1, color = 0) {
        this.geo.render(scale, color);
    }

    swap() {
        this.on = !this.on;
    }
}

class SevenSegment extends Container {
    constructor(x, y) {
        super();
        this.x = x;
        this.y = y;
        this.long = 80;
        this.short = 10;

        this.segments = [];
        this.colors = '0000000';
    }

    computeColors(number = 0) {
        switch (number) {
            case 0:
                this.colors = '1111110';
                break;
            case 1:
                this.colors = '0110000';
                break;
            case 2:
                this.colors = '1101101';
                break;
            case 3:
                this.colors = '1111001';
                break;
            case 4:
                this.colors = '0110011';
                break;
            case 5:
                this.colors = '1011011';
                break;
            case 6:
                this.colors = '1011111';
                break;
            case 7:
                this.colors = '1110000';
                break;
            case 8:
                this.colors = '1111111';
                break;
            case 9:
                this.colors = '1111011';
                break;
            case 10: case 'a': case 'A':
                this.colors = '1110111';
                break;
            case 11: case 'b': case 'B':
                this.colors = '0011111';
                break;
            case 12: case 'c': case 'C':
                this.colors = '1001110';
                break;
            case 13: case 'd': case 'D':
                this.colors = '0111101';
                break;
            case 14: case 'e': case 'E':
                this.colors = '1001111';
                break;
            case 15: case 'f': case 'F':
                this.colors = '1000111';
                break;
        
            default:
                break;
        }
    }

    render(scale = 1, number = 0) {
        this.computeColors(number);

        this.segments = [];
        
        this.segments.push(
            new Segment(this.x, this.y - scale * (this.long + this.short), this.long, this.short)
        )
        
        this.segments.push(
            new Segment(this.x + scale * (this.long + this.short) / 2, this.y - scale * (this.long + this.short) / 2, this.short, this.long)
        )
        
        this.segments.push(
            new Segment(this.x + scale * (this.long + this.short) / 2, this.y + scale * (this.long + this.short) / 2, this.short, this.long)
        )
        
        this.segments.push(
            new Segment(this.x, this.y + scale * (this.long + this.short), this.long, this.short)
        )
        
        this.segments.push(
            new Segment(this.x - scale * (this.long + this.short) / 2, this.y + scale * (this.long + this.short) / 2, this.short, this.long)
        )
        
        this.segments.push(
            new Segment(this.x - scale * (this.long + this.short) / 2, this.y - scale * (this.long + this.short) / 2, this.short, this.long)
        )
        
        this.segments.push(
            new Segment(this.x, this.y, this.long, this.short)
        )

        for(let i = 0; i < 7; i++) {
            this.segments[i].render(scale, this.colors[i] - '0')
        }
    }
}