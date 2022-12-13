const PI = 3.1415926;

function main() {
  let f1, f2, p2;
  let x1, y1, y2;

  console.log("Relative freq. for x: ");
  f1 = +prompt("Enter relative freq. for x: ");
  if (f1 < 1 || f1 !== parseInt(f1, 10)) {
    console.log("Invalid input.");
    return 1;
  }

  console.log("Relative freq. for y: ");
  f2 = +prompt("Enter relative freq. for y: ");
  if (f2 < 1 || f2 !== parseInt(f2, 10)) {
    console.log("Invalid input.");
    return 1;
  }

  console.log("Y phase, multiple of pi: ");
  p2 = +prompt("Enter Y phase, multiple of pi: ");
  f1 = 2 * PI * f1;
  f2 = 2 * PI * f2;
  p2 = PI * p2;

  for (x1 = -18; x1 <= 18; x1++) {
    let x = x1 / 18.0;
    let t1 = x, t2 = PI - x;

    for (let i = 0; i < f1; i++) {
      let t3 = (t1 + 2 * i * PI) / f1;
      let t4 = (t2 + 2 * i * PI) / f1;
      y1 = 30 * Math.sin(f2 * t3 + p2);
      y2 = 30 * Math.sin(f2 * t4 + p2);
      y1 = (y1 > 0) ? parseInt(y1 + 0.5, 10) : parseInt(y1 - 0.5, 10);
      y2 = (y2 > 0) ? parseInt(y2 + 0.5, 10) : parseInt(y2 - 0.5, 10);

      // Sort and print y1 and y2
      if (y1 < y2) {
        console.log("%*s*\n", 36 + y1, "");
        console.log("%*s*\n", 36 + y2, "");
      } else {
        console.log("%*s*\n", 36 + y2, "");
        console.log("%*s*\n", 36 + y1, "");
      }
    }
  }

  return 0;
}

main();