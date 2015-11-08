#!/usr/bin/perl
my ($n, $x0, $y0) = split " ", <>;
for (my $i = 0; $i < $n; ++$i) {
	my ($x, $y) = split " ", <>;
	print $x0+$y-$y0+$x-$x0, " ", $y0-$x+$x0, "\n";
}
