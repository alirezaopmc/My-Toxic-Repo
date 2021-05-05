class Container {
    constructor() {
        this.children = [];
    }

    add(child) {
        this.children.push(child);
    }

    render(scale = 1) {
        this.children.forEach(child => child.render(scale));
    }
}

class Rectangle extends Container {
    constructor(x, y, w, h) {
        super();
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
    }

    render(scale = 1, color) {
        super.render(scale);
        push();
        fill(color == 1 ? 200 : 50);
        rect(this.x, this.y, this.w * scale, this.h * scale);
        pop();
    }
}