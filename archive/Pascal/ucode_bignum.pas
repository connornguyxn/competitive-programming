//uses crt;
var a,b,t,sstr,nhostr:ansistring;
i,as,bs,s,kt,nho,kq,tth,n,j:longint;

begin
readln(n);
for j:=1 to n do
    begin
    t:='';nho:=0;
    readln(a);
    readln(b);
    ///////////
    for i:=1 to abs(length(a)-length(b)) do
        begin
        if length(a)>length(b) then
            b:='0'+b
        else
            a:='0'+a;
        end;
    ///////////
    for i:=length(a) downto 1 do
        begin
        val(a[i],as,kt);
        val(b[i],bs,kt);
        s:=(as+bs+nho);
        str(s mod 10,sstr);
        t:=sstr+t;
        nho:=as div 10;
        end;
    writeln(t);
    end;
end.
