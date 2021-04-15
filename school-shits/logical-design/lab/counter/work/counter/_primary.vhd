library verilog;
use verilog.vl_types.all;
entity counter is
    port(
        inc             : in     vl_logic;
        dec             : in     vl_logic;
        clk             : in     vl_logic;
        A               : out    vl_logic_vector(1 downto 0)
    );
end counter;
