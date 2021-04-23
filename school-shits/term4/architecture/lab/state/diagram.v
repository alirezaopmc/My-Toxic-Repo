module DFF(clk, D, rst, Q);
    input clk, D, rst;
    output reg Q;

    always @ (posedge clk)
    begin
        if (rst == 1)
            Q <= 0;
        else
            Q <= D;
    end
endmodule

module diagram(clk, rst, QA, QB, X, Y);
    input clk, rst, X;
    output QA, QB, Y;

    wire orAB;
    wire nextA;
    wire nextB;
    wire outY;

    or(orAB, QA, QB);
    and(nextA, orAB, X);
    and(nextB, ~QA, X);
    and(outY, ~X, orAB);

    assign Y = outY;

    DFF dffA(
        .clk(clk),
        .D(nextA),
        .rst(rst),
        .Q(QA)
    );

    DFF dffB(
        .clk(clk),
        .D(nextA),
        .rst(rst),
        .Q(QB)
    );
endmodule