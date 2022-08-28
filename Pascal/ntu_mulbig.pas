uses crt;
var as,bs,i,kt:longint;
a,b:ansistring;
///////////////////////function/////////////////////////////
function tong(a,b:ansistring):ansistring;
var sstr,nhostr:ansistring;
i,as,bs,s,kt,nho,kq,tth:longint;
begin
nho:=0;
for i:=length(a) downto 1 do
    begin
    val(a[i],as,kt);
    val(b[i],bs,kt);
    s:=as+bs+nho;
    str(s mod 10,sstr);
    tong:=sstr+tong;
    nho:=as div 10;
    end;
if nho=1 then tong:='1'+tong;
end;
/////////////////
function nhan(a,b:ansistring):ansistring;
var ts,so0:ansistring;
t:int64;
i,as,bs,kt:longint;
begin
so0:='';
for i:=length(a) downto 1 do
    begin
    val(a,as,kt);
    val(b[i],bs,kt);
    t:=as*bs;
    str(t,ts);
    ts:=ts+so0;
    nhan:=tong(a,ts);
    so0:=so0+'0';
    end;
end;
////////////////////
procedure add0(var a,b:ansistring);
var i:longint;
begin
for i:=1 to abs(length(a)-length(b)) do
    begin
    if length(a)>length(b) then
        b:='0'+b
    else
        a:='0'+a;
    end;
end;
/////////////////////////////main///////////////////////////
begin
clrscr;
readln(as,bs);
val(as,a,kt);
val(bs,b,kt);

readln
end.
