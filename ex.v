module mux4_to_1(inp,selection,out);
  input[3:0] inp;
  input[1:0] selection;
  output out;
  assign out=inp[selection];
endmodule

module mux161(input [15:0] inp,input [3:0] selection, output out);
  wire[3:0] t;
  mux4_to_1 M0(inp[3:0],selection[1:0],t[0]);
  mux4_to_1 M1(inp[7:4],selection[1:0],t[1]);
  mux4_to_1 M2(inp[11:8],selection[1:0],t[2]);
  mux4_to_1 M3(inp[15:12],selection[1:0],t[3]);
  mux4_to_1 M4(t[3:0],selection[3:2],out);
endmodule