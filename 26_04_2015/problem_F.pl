#!/usr/bin/perl
$a = <>;
if ($a == 0) {
	print "-1\n";
	exit;
}
@m = split "", $a;
map{$s+=$_}@m;
while ($s >= 9) {
	$r .= 9;
	$s -= 9;
}
$r .= $s if $s != 0;
if ($r == $a) {
	$r =~ s/^(\d)(\d+)(\d)$/$3$2$1/;
}
if ($r == $a) {
	$r =~ s/^(\d)(\d*)$/"1".($1-1).$2/e;
}
if ($r > 10**9) {
	print "-1\n";
	exit;
}
print $r;
