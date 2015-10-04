#!/usr/bin/perl
use bigint;
my @cmap = qw(  rwwgwwwrwwwgwwr
				wbwwwywwwywwwbw
				wwbwwwgwgwwwbww
				gwwbwwwgwwwbwwg
				wwwwbwwwwwbwwww
				wywwwwwwwwwwwyw
				wwgwwwgwgwwwgww
				rwwgwwwswwwgwwr
				wwgwwwgwgwwwgww
				wywwwwwwwwwwwyw
				wwwwbwwwwwbwwww
				gwwbwwwgwwwbwwg
				wwbwwwgwgwwwbww
				wbwwwywwwywwwbw
				rwwgwwwrwwwgwwr);
my @map;
for (my $i = 0; $i < 16; ++$i) {
	for (my $j = 0; $j < 16; ++$j) {
		$map[$i][$j] = 0;
	}
}
my @alp = (1,3,2,3,2,1,5,5,1,2,2,2,2,1,1,2,2,2,2,3,10,5,10,5,10,10,10,5,5,10,10,3);

my %cl = 
   (w => 1,
    s => 1,
    g => 2,
    y => 3,
    b => 1,
    r => 1);

my %cw = 
   (w => 1,
    s => 1,
    g => 1,
    y => 1,
    b => 2,
    r => 3);

sub getColor {
	my ($x, $y) = @_;
	substr $cmap[$y-1], $x-1, 1;
}
my $str;
$str = <ARGV>;
chomp $str;
my ($n, $m) = split(" ", $str);
my @scores;
for (my $i = 0; $i < $n; ++$i) {
	$scores[$i] = 0;
}
for (my $si = 0; $si < $m; ++$si) {
	my $str = <ARGV>;
	chomp $str;
	my $w = $str;
	my $count = 0;
	my $score = 0;
	for (my $i = 0; $i < $w; ++$i) {
		$str = <ARGV>;
		chomp $str;
		my @A = split(" ", $str);
		my $l = shift @A;
		my $dir = shift @A;
		my $x = shift @A;
		my $y = shift @A;
		my $scoreL = 0;
		my $scoreW = 1;
		for my $char (@A) {
			my $color = getColor($x, $y);
			unless ($map[$x][$y]) {
				$map[$x][$y] = 1;
				++$count;
			}

			$scoreL += $cl{$color} * $alp[$char-1];
			$scoreW *= $cw{$color};
			if ($dir eq 'v') {
				++$y;
			}
			else {
				++$x;
			}
		}
		$score += $scoreW * $scoreL;
	}
	if ($count == 7) {
		$score += 15;
	}
	$scores[$si%$n] += $score;
}
print join("\n", @scores), "\n";