type ar=array[1..10000] of longint;
var a:ar;

procedure sangfibo(var a:ar);
var i:longint;
    begin
    a[1]:=1;
    a[2]:=1;
    for i:=3 to sizeof(ar) do
        a[i]:=(a[i-1] mod 1000000007 + a[i-2] mod 1000000007) mod 1000000007;
    end;

begin
assign(input,'ucode_fibosum.inp');reset(input);
assign(output,'ucode_fibosum.out');rewrite(output);





end.














end.