const tests_amount = 10
var total = 0

function test(){
	for(var i = 0; i < tests_amount; ++i){
		var begin = new Date().getTime()
		
		lst = new Array(10000000)			
		for(var j = 0; j < lst.length; ++j){
			lst[j] = {'name': j.toString(), 'amount': j}
		}
		
		var sum = lst.reduce((a,b) => a + b['amount'], 0)		
		var end = new Date().getTime()		
		var elapsed = end - begin	
		total += elapsed
		console.log(sum)
		console.log(`Elapsed: ${elapsed} ms.`)
	}
	var mean = total / tests_amount
	console.log(`Mean: ${mean} ms.`)
}

test()