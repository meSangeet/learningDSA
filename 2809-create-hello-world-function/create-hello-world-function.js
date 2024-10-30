/**
 * @return {Function}
 */
var createHelloWorld = function() {
    var returnValue = "Hello World"
    return function(...args) {
        return returnValue
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */