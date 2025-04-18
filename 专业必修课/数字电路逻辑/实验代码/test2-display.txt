module test (
    input[15:0] sw_i,
    output[6:0] disp_seg_o 
);
reg [6:0]tmp;
always@(*)
begin
    case(sw_i)
        4'b0000:tmp=7'b111_1110;
		4'b0001:tmp=7'b011_0000;
		4'b0010:tmp=7'b110_1101;
		4'b0011:tmp=7'b111_1001;
		4'b0100:tmp=7'b011_0011;
		4'b0101:tmp=7'b101_1011;
		4'b0110:tmp=7'b001_1111;
		4'b0111:tmp=7'b111_0000;
		4'b1000:tmp=7'b111_1111;
		4'b1001:tmp=7'b111_1011;  
		//以下为无效状态
  		4'b1010:tmp=7'b000_0000;
  		4'b1011:tmp=7'b000_0000; 
  		4'b1100:tmp=7'b000_0000;
  		4'b1101:tmp=7'b000_0000;
  		4'b1110:tmp=7'b000_0000;
  		4'b1111:tmp=7'b000_0000; 
        default:tmp=7'b000_0000; 
    endcase
end
assign disp_seg_o = tmp;
endmodule