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
Required Problem set 8 by Luis Artavia
draft processed on: September 24, 2023 and September 25, 2023
submitted for grade on: September 25, 2023
*/