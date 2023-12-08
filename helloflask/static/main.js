(function() {

    const init = () => {

        // console.log('konichiwa');

        const arrayAnchors = toArray(document.querySelectorAll("a.navbar-brand"));

        arrayAnchors.forEach((el, idx, arr) => {
            el.addEventListener("click", doNotLaunch, false);
        });

    };

    const doNotLaunch = (evt) => {
        evt.preventDefault();
        // alert( "It's go time!" );
    };

    const toArray = (arr) => {
        return Array.prototype.slice.call(arr);
    }

    window.document.addEventListener('DOMContentLoaded', init, false);

})();

/*
Optional Lab 9 by Luis Artavia - helloflask
draft processed on: October 03, 2023
Composed on: October 03, 2023
Practice document not intended for evaluation
*/