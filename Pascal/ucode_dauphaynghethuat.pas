var last_number,commas_used:int64;
    i:int64;
////////////////////
function stri(number:int64):ansistring;
begin
str(number,stri);
end;
////////
function int(strin:ansistring):int64;
var check:longint;
begin
val(strin,int,check);
end;
/////////
function commas_in_with_length(number_length:int64):int64;
var pow9:ansistring;
    number_count:int64;
begin
pow9:='9';
for i:=2 to number_length do
    pow9:=pow9+'0';
commas_in_with_length:=number_length div 3;
if (number_length mod 3<>0) then
    commas_in_with_length:=commas_in_with_length+1;
commas_in_with_length:=commas_in_with_length*number_count;
end;
/////////////////////
begin
readln(last_number);
for i:=4 to length(stri(last_number))-1 do
    begin
    commas_used:=commas_used+commas_in_with_length(i);
    writeln('commas_used ', commas_used);
    writeln('commasinwith ', commas_in_with_length(i));
    end;
writeln(commas_used);
end.