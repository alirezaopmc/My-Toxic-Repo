module bcd_to_seven_segment (
    bcd,
    seven_segment
);

input [3:0] bcd;
output reg [6:0] seven_segment;

always@ (bcd)
begin
    case(bcd)
        0 : seven_segment = 7'b0000001;
        1 : seven_segment = 7'b1001111;
        2 : seven_segment = 7'b0010010;
        3 : seven_segment = 7'b0000110;
        4 : seven_segment = 7'b1001100;
        5 : seven_segment = 7'b0100100;
        6 : seven_segment = 7'b0100000;
        7 : seven_segment = 7'b0001111;
        8 : seven_segment = 7'b0000000;
        9 : seven_segment = 7'b0000100;
    default: seven_segment = 7'bx;
    endcase
end

endmodule



module bcd_test();

reg [3:0] bcd;
wire [6:0] seven_segment;
integer i;

bcd_to_seven_segment test(bcd, seven_segment);

initial begin

for(i = 0;i < 8;i = i+1)
begin
    bcd = i; 
    #15;
end  

end
endmodule