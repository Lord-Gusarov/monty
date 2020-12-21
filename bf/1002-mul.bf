,               c0 read char
>,              c1 read char
#After getting input; substract 48 from both
>+++++ +++      c2 set 8
[
 >+++++ +       c3 set 6
 [
  <<-           c1 sub 1
  <-            c0 sub 1
  >>>-          cnt c3 sub 1
 ]
 <-             cnt c2 sub 1
]               c0 and c1 now [0:9]
#Multiplication to start
<<              c0
[
 >              c1
 [
  -             c1 sub 1
  >+            c2 add 1
  >+            c3 add 1
  <<            c1
 ]
 >              c2
 [
  -             c2 sub 1
  <+            c1 add 1
  >             c2
 ]
 <<-            c0 sub 1
]
#Multiplication finished; now add 48 to be printable char
>>>>+++++ +++   c4 set 8
[
 >+++++ +       c5 set 6
 [
  <<+           c3 add 1
  >>-           c5 sub 1
 ]
 <-             c4 sub 1
]
<.              c3 out
