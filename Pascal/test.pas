var  n,i,ai,aj,d:longint;a,b:array[0..100] of int64;max,miin:int64;
///////
function min(a,b:int64):int64;
begin
if a>b then min:=b else min:=a;
end;
///
begin
readln(n);
for i:=1 to n do
 begin
 read(a[i]);
 if a[i]=1 then inc(d);
 if a[i]=0 then b[i]:=b[i]+1
  else b[i]:=b[i]-1;
 end;
for i:=1 to n do b[i]:=b[i-1]+b[i];
miin:=maxlongint;max:=0;
for i:=1 to n do
 begin
 if b[i]<miin then begin miin:=b[i]; ai:=i+1; end;
 if b[i]-miin>max then begin max:=b[i]-miin; aj:=i; end;
 end;
writeln(max+d);
end.