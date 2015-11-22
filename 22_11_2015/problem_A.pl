my %digits = (
	"xxxxx".
	"x...x".
	"x...x".
	"x...x".
	"x...x".
	"x...x".
	"xxxxx" => 0,
	"....x".
	"....x".
	"....x".
	"....x".
	"....x".
	"....x".
	"....x" => 1,

	"xxxxx".
	"....x".
	"....x".
	"xxxxx".
	"x....".
	"x....".
	"xxxxx" => 2,

	"xxxxx".
	"....x".
	"....x".
	"xxxxx".
	"....x".
	"....x".
	"xxxxx" => 3,

	"x...x".
	"x...x".
	"x...x".
	"xxxxx".
	"....x".
	"....x".
	"....x" => 4,

	"xxxxx".
	"x....".
	"x....".
	"xxxxx".
	"....x".
	"....x".
	"xxxxx" => 5,

	"xxxxx".
	"x....".
	"x....".
	"xxxxx".
	"x...x".
	"x...x".
	"xxxxx" => 6,

	"xxxxx".
	"....x".
	"....x".
	"....x".
	"....x".
	"....x".
	"....x" => 7,

	"xxxxx".
	"x...x".
	"x...x".
	"xxxxx".
	"x...x".
	"x...x".
	"xxxxx" => 8,

	"xxxxx".
	"x...x".
	"x...x".
	"xxxxx".
	"....x".
	"....x".
	"xxxxx" => 9,

	".....".
	"..x..".
	"..x..".
	"xxxxx".
	"..x..".
	"..x..".
	"....." => "+"
	);
my %dig;
foreach my $key (keys %digits) {
	$dig{$digits{$key}} = $key;
}
my @screen;
for (my $i = 0; $i < 7; ++$i) {
	my $str = <>;
	chomp $str;
	my $n = length($str)+1;
	my $dig_cnt = $n/6;
	for (my $j = 0; $j < $dig_cnt; ++$j) {
		my $a = substr substr($str, $j*6, 6), 0, 5;
		$screen[$j] .= $a;
	}
}
my $expr = "";
foreach my $s (@screen) {
	$expr .= $digits{$s};
}
my $res = eval $expr;
for (my $i = 0; $i < 7; ++$i) {
	my $str = "";
	foreach my $d (split "", $res) {
		my $a = substr $dig{$d}, $i*5, 5;
		$str .= $a.".";
	}
	chop $str;
	print $str, "\n";
}