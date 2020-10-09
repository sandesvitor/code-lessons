function getMiddle(s)
{
  return (s.length % 2) == 0 
    ? `${s[parseInt((s.length - 1)/ 2)]}${s[parseInt(((s.length - 1) / 2)) + 1]}` 
    : `${s[parseInt((s.length - 1)/ 2)]}`
}

console.log(getMiddle('testing'))
