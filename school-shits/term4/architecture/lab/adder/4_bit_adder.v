module FourBitAdder(a, b, c, sum, carry);
    input [3:0] a;
    input [3:0] b;
    input c;
    output [3:0] sum;
    output carry;
    wire carry_01;
    wire carry_12;
    wire carry_23;
endmodule

module FourBitAdderTest;
    reg [3:0] a;
    reg [3:0] b;
    reg c;
    wire [3:0] sum;
    wire carry;

    FullAdder bit_1 (
        .a(a[0]),
        .b(b[0]),
        .c(0),
        .sum(sum[0]),
        .carry(carry_01)
    );

    FullAdder bit_2 (
        .a(a[1]),
        .b(b[1]),
        .c(carry_01),
        .sum(sum[1]),
        .carry(carry_12)
    );

    FullAdder bit_3 (
        .a(a[2]),
        .b(b[2]),
        .c(carry_12),
        .sum(sum[2]),
        .carry(carry_23)
    );

    FullAdder bit_4 (
        .a(a[3]),
        .b(b[3]),
        .c(carry_23),
        .sum(sum[3]),
        .carry(carry)
    );

    initial begin
        a = 4'b0100;
        b = 4'b1011;

        #50

        a = 4'b0001;
        b = 4'b0111;

        #50

        a = 4'b0110;
        b = 4'b0011;

        #50
        a = 4'b1111;
        b = 4'b0001;
    end
endmodule

