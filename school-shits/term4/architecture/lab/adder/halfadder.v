module HalfAdder(a, b, sum, carry);
    input a, b;
    output sum, carry;
    assign sum = (!a & b) | (a & !b);
    assign carry = a & b;
endmodule


module TestHalfAdder;
    reg a, b;
    wire sum, carry;

    HalfAdder ha (
        .a(a),
        .b(b),
        .sum(sum),
        .carry(carry)
    );

    initial begin
        a = 0;
        b = 0;

        #50

        a = 1;
        b = 0;

        #50

        a = 0;
        b = 1;

        #50

        a = 1;
        b = 1;
    end
endmodule