library verilog;
use verilog.vl_types.all;
entity FourBitAdder is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        c               : in     vl_logic;
        sum             : out    vl_logic_vector(3 downto 0);
        carry           : out    vl_logic
    );
end FourBitAdder;
