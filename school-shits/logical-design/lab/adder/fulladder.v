module FullAdder(a, b, c, sum, carry);
    input a, b, c;
    output sum, carry;
    wire w1 = !a & !b & c;
    wire w2 = !a & b & !c;
    wire w3 = a & !b & !c;
    wire w4 = a & b & c;
    wire w5 = b & c;
    wire w6 = a & c;
    wire w7 = a & b;
    assign sum = w1 | w2 | w3 | w4;
    assign carry = w5 | w6 | w7;
endmodule


module TestFullAdder;
    reg a, b, c;
    wire sum, carry;

    FullAdder ha (
        .a(a),
        .b(b),
        .c(c),
        .sum(sum),
        .carry(carry)
    );

    initial begin
        a = 0;
        b = 0;
        c = 0;

        #50
        a = 1;
        b = 0;
        c = 0;

        #50
        a = 0;
        b = 1;
        c = 0;

        #50
        a = 1;
        b = 1;
        c = 0;

        #50
        a = 0;
        b = 0;
        c = 1;

        #50
        a = 1;
        b = 0;
        c = 1;

        #50
        a = 0;
        b = 1;
        c = 1;

        #50
        a = 1;
        b = 1;
        c = 1;
    end
endmodule