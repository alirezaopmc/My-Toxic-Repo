library verilog;
use verilog.vl_types.all;
entity bcd_to_seven_segment is
    port(
        bcd             : in     vl_logic_vector(3 downto 0);
        seven_segment   : out    vl_logic_vector(6 downto 0)
    );
end bcd_to_seven_segment;
