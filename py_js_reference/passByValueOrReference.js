function change_arr(arr) {
  let arrr = JSON.parse(JSON.stringify(arr));
  arrr.splice(0, 1);

  console.log(arrr);
}

function main() {
  let arr = [1, 2, 3];

  change_arr(arr);
  console.log(arr);
}
main();
